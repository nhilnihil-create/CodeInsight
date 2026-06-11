#include<bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long int ll;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin>>n;
    int a[n]={0};
    for(int i=0;i<n;i++){
    	cin>>a[i];
    }
    bitset<4000010>poss;
    poss[0]=1;
    for(int i=0;i<n;i++){
    	poss|=(poss<<a[i]);
    }
    int sum=0;
    for(int i=0;i<n;i++){
    	sum+=a[i];
    }
    //cout<<sum<<endl;
    for(int i=sum/2+(sum%2);i<=sum;i++){
    	//cout<<i<<endl;
    	if(poss[i]==1){
    		cout<<i<<endl;
    		return 0;
    	}
    }
    

	return 0;
}