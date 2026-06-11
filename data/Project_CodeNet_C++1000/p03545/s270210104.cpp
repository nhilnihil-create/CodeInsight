#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define debug(x) cerr<<#x<<": "<<x<<endl;
#define rep(i,n) for(int i=0;i<n;i++)
const int MOD = 1000000007;



int main() {
	char S[5];
  	rep(i,4) cin>>S[i];
  	char op[3];
  
  	for(int bit=0;bit<(1<<3);bit++){
      	int ans=S[0]-'0';
     	for(int i=0;i<3;i++){
         	 if(bit&(1<<i)){
             	op[i]='+';
               	ans+=S[i+1]-'0';
             }else{
                op[i]='-';
               	ans-=S[i+1]-'0';
             }
        }
      	if(ans==7){
         	break; 
        }
    }
  	
  	cout<<S[0];
  	rep(i,3){
     	cout<<op[i]<<S[i+1]; 
    }
  	cout<<"=7"<<endl;
  	
}