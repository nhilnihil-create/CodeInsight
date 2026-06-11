#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int N;
  long long x;
  cin >> N >> x;
  vector<long long> a;
  for (int i = 0; i < N; i++){
    long long tmp;
    cin >> tmp;
    a.push_back(tmp);
  }

  sort(a.begin(), a.end());
  int ans=0;
  for (int i = 0; i < N; i++){
    if (x - a[i] < 0){
      break;
    }
    x -= a[i];
    ans++;
  }
  if (x==0){
    printf("%d\n",ans);
  }else if(ans==N && x > 0){
    printf("%d\n",ans-1);
  }else{
    printf("%d\n",ans);
  }
  
}
