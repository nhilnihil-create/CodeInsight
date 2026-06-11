    using namespace std;
    #include <iostream>
    int main(){
      int N, a[10000], i, result;
      cin >> N;
      result = 0;
      for(i = 0; i < N; i++){
        cin >> a[i];
        while(a[i]%2 == 0){
          a[i] = a[i]/2;
          result++;
        }
      }
      cout << result << endl;
      return(0);
    }