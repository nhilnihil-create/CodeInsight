#include<bits/stdc++.h>
using namespace std;
#define MAX_N (int)1e5
int h, w;
int a[500][500];
typedef pair<int , int> P;
typedef pair<P, P> PP;
#define MP make_pair
vector<PP> vec;
int direct(int i){
    return i % 2 ? -1 : 1;
}
int main(){
   cin >> h >> w;
   int sum = 0;
   for(int i = 0; i < h; i++){
       for(int j = 0; j < w; j++){
           cin >> a[i][j];
           sum += a[i][j];
        }
   }
    for(int i = 0; i < h; i++){
        for(int j = i % 2 ? w - 1 : 0; j < w && j >= 0; j += i % 2 ? -1 : 1){
            if(a[i][j] % 2){
                a[i][j]--;
                if(j + direct(i) < w && j + direct(i) >= 0){
                    a[i][j + direct(i)]++;
                    vec.push_back(MP(MP(i + 1, j + 1), MP(i + 1, j + direct(i) + 1)));
                 }
                else{
                    if(i + 1 >= h){
                        break;
                    }
                    a[i + 1][j]++;
                    vec.push_back(MP(MP(i + 1, j + 1), MP(i + 2, j + 1)));
                }
            }
        }
    }
    cout << vec.size() << endl;
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i].first.first << " " << vec[i].first.second << " " << vec[i].second.first << " " << vec[i].second.second << endl; 
    }
}