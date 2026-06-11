#include<bits/stdc++.h>

#define rep(i,n) for(int i = 0; i < (n); i++)
#define ll long long

using namespace std;

string q(int i){
  cout<<i<<endl;
  string t;cin>>t;
  return t;
}

int main(){
  int n;cin>>n;

  int min=0, max=n-1, mid=0;
  string c=q(0);
  if(c=="Vacant"){ cout<<0;return 0; }

//cout<<max<<' '<<min;

  while(max-min>1){
    mid=(min+max)/2;
    string mc;
    mc = q(mid);
    if(mc=="Vacant")return 0;
    // 偶数位置に0indexと異なる性別の人間が座っている
    // もしくは奇数位置に0indexと同じ性別の人間が座っている
    // つまりmidよりも前に空席が存在して順番をずらしている
    if(mid%2==0 && mc!=c || mid%2==1 && mc==c) max=mid;
    else min=mid;
//cout<<max<<' '<<min<<' '<<mid<<endl;
  }
  q(mid-1);
  q(mid+1);

  
cout<<"###"<<endl;
  return 0;
}