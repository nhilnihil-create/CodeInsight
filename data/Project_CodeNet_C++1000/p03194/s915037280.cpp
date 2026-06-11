#include<iostream>
using namespace std;

int main(){
  long long N,num,ans=1,was=0,temp=1,i,cnt=0;
  bool chk=false;
  cin>>N>>num;
  if(N==1){
    cout<<num<<endl;
    return 0;
  }
  while(num!=0){
 	for(i=2;i<=num;i++){
 		if(num%i==0 && num!=2){
			chk=true;
			break;
		}
		if(num/i<i || num==2){
			chk=false;
			break;
		}
 	}
	if(chk==true){
	  if(was==i)temp++;
      else temp=1;
      was=i;
      if(temp>=N){
        ans*=i;
        temp=0;
      }
	}else{
	  if(was==num)temp++;
      if(temp>=N){
        ans*=num;
        temp=0;
      }
	  break;
	}
	num=num/i;
	cnt++;
  }
  cout<<ans<<endl;
}