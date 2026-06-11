#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int n,m,d,t;
    cin>>n;
    std::map<long long int, long long int> map;
    for (int i=0;i<n;i++) {
        cin>>d;
        map[d]++;
    }
    cin>>m;
    for (int i=0;i<m;i++) {
        cin>>t;
        if (map[t]>0) {
            map[t]--;
        } else {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;
}