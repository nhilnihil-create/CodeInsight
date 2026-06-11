#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    cin >> n;
    vector<tuple<string,int,int>> a;
    
    for(int i = 1; i <= n;i++){
          string s;
          int p;
          cin >> s >> p;
          p *= -1;
          a.push_back(tie(s,p,i));
    }
    sort(a.begin(),a.end());
    for(int i = 0;i < n;i++){
          cout << get<2>(a[i]) << endl;
    }
}
