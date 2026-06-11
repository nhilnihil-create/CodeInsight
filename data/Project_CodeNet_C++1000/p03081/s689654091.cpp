#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <numeric>
#include <string>
#include <math.h>

typedef long long ll;
using namespace std;

int main(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> vs;
    for (auto ch : s){
        vs.push_back(ch-'A');
    }
    vector<int> t(q),d(q);
    for (int i=0; i<q; ++i){
        char ch;
        cin >> ch;
        t[i] = ch-'A';
        cin >> ch;
        d[i] = (ch=='R') ? 1 : -1;
    }
    reverse(t.begin(), t.end());
    reverse(d.begin(), d.end());
    
    int l=0, r=n-1;
    for(int i=0; i<q; ++i){
        // left end
        if(t[i] == vs[l] && d[i]<0){
            ++l;
        }else if(l>0 && t[i] == vs[l-1] && d[i]>0){
            --l;
        }
        
        //right end
        if (t[i] == vs[r] && d[i]>0){
            --r;
        }else if(r<n-1 && t[i] == vs[r+1] && d[i]<0){
            ++r;
        }
    }
    cout << r-l+1 << endl;
    
    return 0;
}
