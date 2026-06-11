#include <iostream>
#include <map>
#include <vector>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int P[N];
    map<int, int> m;
    for(int i=0; i<N; i++){
        cin >> P[i];
        P[i]--;
        m[P[i]] = i;
    }


    vector<vector<int>> v(N);
    v[0].push_back(0);
    int ind = 0;
    for(int i=0; i<N-1; i++){
        if(m[i]<m[i+1]){
            v[ind].push_back(i+1);
        }else{
            ind++;
            v[ind].push_back(i+1);
        }
    }

    int len = 0;
    for(int i=0; i<N; i++){
        int t = v[i].size();
        len = max(t, len);
    }

    cout << N-len << endl;

    return 0;
}
