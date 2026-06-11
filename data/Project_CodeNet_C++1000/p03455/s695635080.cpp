#include <bits/stdc++.h>
using namespace std;
using lli=long long int;
using vi=vector<int>;  using vs=vector<string>; using gi=greater<int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define soao(c) sort((c).begin(),(c).end()) //昇順
#define sodo(c) sort((c).begin(),(c).end(),gi()) //降順
#define rev(c) reverse((c).begin(), (c).end())



int main(){
	int a,b; cin>>a>>b;
	if(a%2==0||b%2==0) cout<<"Even"<<endl;
	else cout<<"Odd"<<endl;
}
