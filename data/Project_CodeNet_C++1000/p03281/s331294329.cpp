#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N;
    cin >> N;
    int count = 0;
    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum = 0;
            for(int j = 1; j <= N; j++){
                if(i%j == 0){
                    sum++;
                }
                else continue;
            }
        if(sum == 8){
            count++;
        }
      i++;
    }
    cout << count << endl;
}