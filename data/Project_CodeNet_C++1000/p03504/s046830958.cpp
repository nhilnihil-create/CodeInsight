#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int N, C;
    cin >> N >> C;
    vector<int> vec(1e5*2+2, 0);
    vector<multiset<int> > ccc(1e5+1);
    for(int n=0; n<N; n++) {
        int s, t, c;
        cin >> s >> t >> c;

        if(ccc[s].count(c)) {
            vec[s*2]++;
            vec[t*2]--;
            continue;
        } else if(ccc[t].count(c)) {
            vec[s*2-1]++;
            vec[t*2-1]--;
            continue;
        }
        
        ccc[s].insert(c);
        ccc[t].insert(c);

        vec[s*2-1]++;
        vec[t*2]--;
    }
    int ans=vec[0];
    for(int n=0; n<vec.size()-1; n++) {
        vec[n+1] += vec[n];
        
        ans = max(vec[n+1], ans);
    }
    
    cout << min(ans, C) << endl;


    return 0;
    
}