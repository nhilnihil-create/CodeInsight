#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    int all = 1;
    int bad = 1;
    for(int i = 0;i < n;i++){
          cin >> a[i];
          all *= 3;
          if(a[i] % 2 == 0){
                bad *= 2;
          }
    }
    cout << all - bad << endl;
}
