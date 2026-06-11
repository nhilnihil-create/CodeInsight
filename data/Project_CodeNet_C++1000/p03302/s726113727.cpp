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
    int a,b;
    cin>>a>>b;
    if(a+b==15)cout<<"+"<<endl;
    else if(a*b==15)cout<<"*"<<endl;
    else cout<<"x"<<endl;
    return 0;
}