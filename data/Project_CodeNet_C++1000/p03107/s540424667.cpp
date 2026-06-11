#include <iostream>
#include <stack>
using namespace std;
const int maxn=100000+5;
const int maxnm=1500+5;
const int mod=1000000007;
const int base=131;
int n;
int hs[maxn];
stack<int> sum;
int main (){
	string s;
    cin>>s;
    int n=s.length();
	for (int i=0;i<n;i++){
        int k=1;
		k=(k*base+s[i]-'0')%mod;
		hs[i]=k;
	}
    int res=0;
	for (int i=0;i<n;i++){
        if(!sum.empty()&&hs[i]!=sum.top()){
        sum.pop();
        res+=2;
        }
        else sum.push(hs[i]);
    }
    cout<<res;
	return 0;
}