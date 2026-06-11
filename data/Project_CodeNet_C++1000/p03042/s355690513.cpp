#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main() {
    int n;cin>>n;
    int n1 = n/100;
    int n2 = n%100;
    
    int c1 = 0;
    int c2 = 0;

    if(n1>=1 && n1<=12)c1=1;
    if(n2>=1 && n2<=12)c2=1;
    
    if(c1+c2 == 2)cout<<"AMBIGUOUS"<<endl;
    else if(c1+c2 == 0)cout<<"NA"<<endl;
    else if(c1 == 1)cout<<"MMYY"<<endl;
    else cout<<"YYMM"<<endl;
    
	return 0;
}