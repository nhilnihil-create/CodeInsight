#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;

using namespace std;
#define X 15
vector<pair<int,int> > v[30];
int cnt;
void make(int a,int b,int len){
    v[a].push_back(make_pair(b,len));
    cnt++;
}
int f(){
    int s=1;
    lol(i,X-1)s*=3;
    return s;
}
int main(){
    cnt=0;
    int n;cin>>n;
    int sum=0;
    int k=f();
    lol(i,X){
	for(int j=1;j<=n/k;j++){
	    make(1,i+2,sum);
	    sum+=k;
	}
	n%=k;
	k/=3;
    }
    k=f()/3;
    lol(i,X-1){
	lol(j,3)make(i+2,i+3,j*k);
	k/=3;
    }
    lol(i,30)for(auto x:v[i])if(x.second>1000000)cnt--;
    cout<<X+1<<" "<<cnt<<endl;
    lol(i,30){
	for(auto x:v[i]){
	    if(x.second>1000000)continue;
	    int a=i,b=x.first;
	    if(a>b)swap(a,b);
	    cout<<a<<" "<<b<<" "<<x.second<<endl;
	}
    }
    return 0;
}
