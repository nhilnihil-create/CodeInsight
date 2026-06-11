#include<iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int Max = 1000000;
int main(){
  	int N;
    cin >> N;
    int a[N];
    for(int i=0;i<N;i++) cin >> a[i];

    int ans = 0;
    int i=0;
    while(i<N-1){
      int cnt = 1;
      while(a[i]==a[i+1]){
        cnt++;
        i++;
      }
      i++;
      ans += cnt/2;
    }
    cout << ans <<endl;
  	return 0;
}