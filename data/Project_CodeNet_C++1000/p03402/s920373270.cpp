#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<queue>
#include<vector>
#include <bitset>
#include <cmath>
#include <limits>
#include <iostream>
#include<set>
using namespace std;
#define INF 100000
#define MAX 100000
#define MOD 1000000007n
typedef long long ll;
typedef pair<int,int> P;
typedef pair<pair<int,int>,int> p;
//typedef pair< pair<int,int>, int> p; 
#define bit(n,k) ((n>>k)&1) /*nのk bit目*/
#define rad_to_deg(rad) (((rad)/2/M_PI)*360)

int main(){
  char ans[110][110];
  int W,B;
  cin>>W>>B;
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++){
      char c;
      if(i<=50) c='.';
      else c='#';
      ans[i][j]=c;
    }
  }
  W--; B--;
  bool flag=false;
  int count=0;
  for(int i=1;;i+=2){
    for(int j=1;j<=100;j+=2){
      if(count>=B){
        flag=true; break;
      }
      count++;
      ans[i][j]='#';
    }
    if(flag) break;
  }

  flag=false;
  count=0;
  cout<<100<<" "<<100<<endl;
  for(int i=100;;i-=2){
    for(int j=1;j<=100;j+=2){
      if(count>=W){
        flag=true; break;
      }
      count++;
      ans[i][j]='.';
    }
    if(flag) break;
  }
  for(int i=1;i<=100;i++){
    for(int j=1;j<=100;j++) cout<<ans[i][j];
    cout<<endl;
  }

}

