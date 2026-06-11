        #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
	  int N;
      int ans =0;
      cin >> N;
      vector<int> vec(N);
      for(int i=0; i<N;i++) cin >>vec.at(i);
      sort(vec.begin(), vec.end());
      reverse(vec.begin(), vec.end());
      if (N%2==0){
        for (int j=0; j<N; j+=2){
          ans += vec.at(j)-vec.at(j+1);
        }
        cout << ans << endl;
      }
      else {
        for (int k=0; k<N-1; k+=2){
          ans += vec.at(k)-vec.at(k+1);
        }
        ans += vec.at(N-1);
        cout << ans << endl;
      }
          
    }