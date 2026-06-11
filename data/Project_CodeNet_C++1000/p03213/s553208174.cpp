#include <bits/stdc++.h>


typedef long long ll;

using namespace std;


const ll mod=1000000007;

ll gcd(ll a, ll b){
  if(a%b == 0){
    return b;
  }else{
    return gcd(b, a%b);
  }
}

ll lcm(ll a,ll b){
    return (a*b)/gcd(a,b);
}
 

int main(){

    int N;
    cin>>N;

    map<int,int> m;

    for(int n=1;n<=N;n++){
        int p=n;
       for(int i=2;i*i<=n;i++){
           int count=0;
           if(p%i!=0)continue;
           while(p%i==0){
              
               ++count;
                p/=i;
           }
           m[i]+=count;
           //cout<<i<<":"<<count<<endl;
       }
       if(p!=1)++m[p];
         //cout<<p<<":"<<1<<endl;
    }

    vector<int> vec(6,0);
    for(map<int,int>::iterator itr=m.begin();itr!=m.end();++itr){
       // cout<<itr->first<<":"<<itr->second<<endl;
        if(itr->second>=74){
            ++vec[0];
        }else if(itr->second>=24){
            ++vec[1];
        }else if(itr->second>=14){
            ++vec[2];
        }else if(itr->second>=4){
            ++vec[3];
        }else if(itr->second>=2){
            ++vec[4];
        }else{
            ++vec[5];
        }
       
    }
     //cout<<vec[0]<<":"<<vec[1]<<":"<<vec[2]<<":"<<vec[3]<<":"<<vec[4]<<endl;
        int ans=(vec[0]+vec[1])*(vec[0]+vec[1]+vec[2]+vec[3]+vec[4]-1);
            ans+=(vec[0]+vec[1]+vec[2])*(vec[0]+vec[1]+vec[2]+vec[3]-1);
            ans+=(vec[0]+vec[1]+vec[2]+vec[3])*(vec[0]+vec[1]+vec[2]+vec[3]-1)/2*(vec[0]+vec[1]+vec[2]+vec[3]+vec[4]-2);
            ans+=vec[0];
        cout<<ans<<endl;
   

    
    
}


