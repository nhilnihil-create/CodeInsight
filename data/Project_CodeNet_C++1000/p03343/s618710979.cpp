#include<iostream>
#include<vector>
using namespace std;

int main(){
  int N, K, Q;
  cin >> N >> K >> Q;

  vector<int> A(N);
  for(auto& x: A){
    cin >> x;
  }
  //banpei
  A.push_back(0);
  N++;
  

  int ans = 1e9;
  for(int X: A){
    // cout << "X: " << X << endl;
    vector<int> removal;

    int start = 0;
    for(int i = 0; i < N; i++){
      if(A[i] < X){
        vector<int> interval;
        for(int j = start; j < i; j++){
          interval.push_back(A[j]);
        }
        sort(interval.begin(), interval.end());

        /*
        cout << "Interval: ";
        for(auto x: interval){
          cout << x << ' ';
        }cout << endl;
        */

        for(int j = 0; j < static_cast<int>(interval.size()) - K + 1; j++){
          removal.push_back(interval[j]);
        }
        start = i + 1;
      }
    }
    /*
    cout << "Removal: ";
    for(auto r: removal){
      cout << r << ' ';
    }cout << endl;
    */
    
    sort(removal.begin(), removal.end());
    if(removal.size() >= Q){
      ans = min(ans, removal[Q - 1] - X);
    }
    
  }
  cout << ans << endl;

}
