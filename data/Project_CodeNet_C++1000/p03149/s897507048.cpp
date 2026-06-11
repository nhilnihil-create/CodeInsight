#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descsort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    string n1,n2,n3,n4;
    cin>>n1>>n2>>n3>>n4;
    string s=n1+n2+n3+n4;
    if(count(s.begin(),s.end(),'1')==1 &&
        count(s.begin(),s.end(),'9')==1 && 
        count(s.begin(),s.end(),'7')==1 &&
        count(s.begin(),s.end(),'4')==1) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}