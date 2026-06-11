#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

void chmin(double &a, double b){
  if( a > b){ swap(a,b);} return;}

int main(){
int N; cin >> N;
  vector<int> t(N); vector<int> v(N); int time = 0;
  for(int i = 0; i < N; i++){ cin >> t[i]; time += t[i];}
  for(int i = 1; i < N; i++){ t[i] += t[i-1];}
  for(int i = 0; i < N; i++){ cin >> v[i];}
  
  vector<double> speed(2*time+10,0.0);
  //speed[i]は、 i/2秒における速度の上限に他ならない
  for(int i = 0; i < N; i++){
    int res;
    if(!i){ res = 0;} else{ res = t[i-1];}
    for(int j = 2*res; j <= 2*t[i]; j++){
      
      if( j == 2*res){  int res1;
        if(!i){ res1 = 0;} else{ res1 = v[i-1];}
          speed[j] = min(res1, v[i]);}
      
      else if( j == 2*t[i]){
          speed[j] = min(v[i],v[i+1]);}
      else{
       speed[j] = v[i];}}
  }
  speed[0] = 0.0; speed[2*time] = 0.0;

  for(int i = 1; i < 2*time; i++){
    chmin( speed[i], speed[i-1]+0.5);}

  for(int j = 2*time-1; j >= 0; j--){
    chmin( speed[j], speed[j+1]+0.5);}
  
  double area = 0.0;
  
  for(int i = 0; i < 2*time; i++){
    area += 0.5*(speed[i]+speed[i+1])*0.5;} //高さ*(上底+下底)/2
  
  cout << fixed << setprecision(5) << area << endl;
    

 return 0;}
