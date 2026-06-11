#include <bits/stdc++.h>
using namespace std;
const unsigned int MOD = 1000000007;
#define ll long long
#define PI 3.1416
string day[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int a,b,c;
    while(cin>>a>>b>>c){
        map<int,int>m;
        m[a]++;
        m[b]++;
        m[c]++;
        map<int,int>::iterator it;
        for(it=m.begin();it!=m.end();it++){
            if((it->second) == 1)cout<<(it->first)<<endl;
        }
    }
    return 0;
}
