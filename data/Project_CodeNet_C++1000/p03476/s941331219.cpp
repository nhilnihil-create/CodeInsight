#include<iostream>
#include<vector>
#include<math.h>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
using namespace std;
vector<int> make_map(int size){
	vector<int> pr(size,1);
	pr[0]=0;//1 is not prime
	for(int i=1;i+1<=sqrt(size);i++){
		if(pr[i]==1){//i+1 is prime
			for(int j=2*(i+1);j<size;j+=(i+1)){//2*(i+1),3*(i+1),... is not prime
				pr[j-1]=0;
			}
		}
	}
	return pr;
}





int main(){
	int q;
	cin>>q;
	vector<int>l(q),r(q),sum(100000,0);
	rep(i,q){
		cin>>l[i]>>r[i];
	}
	vector<int> pr;
	pr = make_map(100000);
	for(int i=1;i<100000;i++){//No.i+1 is checked
		if((i+1)%2==1){// if the no is odd
			if(pr[i]==1&&pr[(i+2)/2-1]){
				sum[i]=sum[i-1]+1;
			}else{
				sum[i]=sum[i-1];
			}
		}else{
			sum[i]=sum[i-1];
		}
	}
	rep(i,q){
		cout<<sum[r[i]-1]-sum[l[i]-2]<<endl;
	}
	return 0;
}
