#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define MOD 1000000007ULL;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	int N,Y;
  	cin>>N>>Y;
  	int res10000=-1,res5000=-1,res1000=-1;
  
  	for(int a=0;a<=N;a++){
     	for(int b=0;a+b<=N;b++){
         	int c=N-a-b;
          	if(10000*a+5000*b+1000*c==Y){
             	res10000=a;
              	res5000=b;
              	res1000=c;
            }
        }
    }
  
  	cout<<res10000<<" "<<res5000<<" "<<res1000<<endl;
}