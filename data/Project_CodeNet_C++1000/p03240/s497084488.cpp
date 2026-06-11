#include<bits/stdc++.h>
using namespace std;
#define rep0(i,n) for(i=0;i<n;i++)
#define test(a) cout << "*" << a << endl;
#define ll long long
int main(){
  int i,j,k;
  int N;
  int x[100];
  int y[100];
  ll h[100];
  ll tmpH;
  ll H;
  int xC,yC;
  bool exist = false;
  int count=0;
  
  cin >> N;
  rep0(i,N){
    cin >> x[i] >> y[i] >> h[i];
  }
  rep0(i,101){
    if(exist)
      break;
    rep0(j,101){
      if(exist)
        break;
      rep0(k,N){
        if(h[k]!=0)
          tmpH = h[k] + abs(x[k]-i/*xC*/) + abs(y[k]-j/*yC*/);
      }
      rep0(k,N){
        if(h[k]==0){
          if(0 != max(tmpH-abs(x[k]-i/*xC*/)-abs(y[k]-j/*yC*/),(ll)0) )  
            break;
        }      
        else{
          if(h[k] != tmpH-abs(x[k]-i/*xC*/)-abs(y[k]-j/*yC*/))
            break;        
        }         
        /*else if(h[k]!=0 && count==0){
          tmpH = h[k] + abs(x[k]-i) + abs(y[k]-j);
          count += 1;
        }
        H = h[k] + abs(x[k]-i) + abs(y[k]-j);
        if(H != tmpH){
          break;
        }*/        
        if(k==N-1){
          exist = true;
          xC = i;
          yC = j;
          break;
        }       
      }
      count = 0;
      
    }
  }
  
  cout << xC << " " << yC << " " << tmpH << endl;
  
 
  
  
}