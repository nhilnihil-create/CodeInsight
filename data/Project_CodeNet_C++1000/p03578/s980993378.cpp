#include <iostream>
#include <map>
#include <vector>
using namespace std;
int A,B,a[1000010],b[1000010];
map<int,int> mpa,mpb;

int main(void){
    cin >> A;
    for(int i = 0;i < A;i++){
          cin >> a[i];
    }
    cin >> B;
    for(int i = 0;i < B;i++){
          cin >> b[i];
    }
    for(int i = 0;i < A;i++){
          mpa[a[i]]++;
    }
    for(int i = 0;i < B;i++){
          mpb[b[i]]++;
    }
    for(int i = 0;i < B;i++){
          if(mpb[b[i]] > mpa[b[i]]){
                cout << "NO" << endl;
                return 0;
          }
    }
    cout << "YES" << endl;
}
