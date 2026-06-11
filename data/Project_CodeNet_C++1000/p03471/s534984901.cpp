#include<bits/stdc++.h>
using namespace std;
int shibaku(int p , int money){
  //2種類(1000円共通)
  for(int j=0;money-5000*j>=0;j++){
 	 if(p==j+(money-5000*j)/1000){
     	cout<<0<<" "<<j<<" "<<p-j<<endl;
       	return 0;
 	 }else if(p==j+(money-10000*j)/1000 && money-10000*j>=0){
       cout<<j<<" "<<0<<" "<<p-j<<endl;
       	return 0;
     }
  }
  return 1;
}
void check(int money,int p){
  int a=p-2,b=1,c=1;
  bool bl=true;
  while(bl){
    int y=10000*a+5000*b+1000*c;
    if(y==money){
    	cout<<a<<" "<<b<<" "<<c<<endl;
    	bl=false;
    } else if(a==1){
       cout<<-1<<" "<<-1<<" "<<-1<<endl;;
       bl=false;
    }else if(b==1){
      a--;
      c=1;
      b=p-a-1;
    }else if(b!=1){
      b--;
      c++;
    }
   
  }
}
  
	

int main(){
  int n,y;//n：お札の枚数y:申告金額
  cin>>n>>y;
  if(y%1000!=0){//yは1000の倍数
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }else if(n>y/1000){
    cout<<-1<<" "<<-1<<" "<<-1<<endl;
  }else if(y%1000==0 &&n==y/1000){
      cout<<0<<" "<<0<<" "<<n<<endl;
  }else if(y%5000==0&&n==y/5000){
      cout<<0<<" "<<n<<" "<<0<<endl;
  }else if(y%10000==0&&n==y/10000){
      cout<<n<<" "<<0<<" "<<0<<endl;
  }else{
    int num=shibaku(n,y);

    if(num!=0){
      check(y,n);
    }
  }
}
    
    
    
  