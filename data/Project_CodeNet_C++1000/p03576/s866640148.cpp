#include <iostream>
#include <vector>
#include <utility>
using namespace std;
int main(){
	int n,k;
	cin >> n >> k;
  vector<pair<int,int>> p(n);
  	for(int i = 0; n > i; i++)
      	cin >> p[i].first >> p[i].second;
  
  long long int Min = -1;
  for(int i = 0; n > i; i++)
  for(int j = 0; n > j; j++)
  for(int kk = 0; n > kk; kk++)
  for(int l = 0; n > l; l++){
  	long long int top = p[i].second,btm=p[j].second,lft=p[kk].first,rgt=p[l].first;
    int count = 0;
    for(int c = 0; n > c; c++){
		if(p[c].first >= lft && p[c].first <= rgt && p[c].second >= btm && p[c].second <= top){
          count++;
        }
    }
    if(count >= k) {
     long long int area = (top - btm) * (rgt - lft);
     if(Min == -1 || Min >area) Min = area; 
    }
  }
    cout << Min << endl;
  return 0;
}