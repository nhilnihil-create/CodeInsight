#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int> vec;
  for(int i=0; i<n-1; i++){
    int c, s, f;
    cin >> c >> s >> f;
    for(int j=0; j<vec.size(); j++){
      if(vec[j] <= s){
        vec[j] = s+c;
      }else{
        if((vec[j]-s) % f == 0){
          vec[j] = vec[j]+c;
        }else{
          vec[j] = vec[j]+f-((vec[j]-s)%f)+c;
        }
      }
    }
    vec.push_back(c+s);
  }
  for(int i=0; i<n-1; i++){
    cout << vec[i] << endl;
  }
  cout << 0 << endl;
  return 0;
}