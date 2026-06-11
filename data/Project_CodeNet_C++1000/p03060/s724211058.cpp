#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<int> v(N);
    vector<int> c(N);
    vector<int> s(N);
    int X = 0;
    if(N==1){
        cout<<0<<endl;
    }else{
    for(int i = 0;i<N;i++){
       cin >> v.at(i);
    }
    for(int i = 0;i<N;i++){
       cin >> c.at(i);
    }
     for (int i = 0; i < N; i++) {
         s.at(i) = v.at(i) - c.at(i);
  }
        sort(s.begin(), s.end());
        reverse(s.begin(), s.end());
        for(int i=0;i<N;i++){
            if(s.at(i)<0){
                s.at(i)=0;
            }
            X += s.at(i);
        }
        cout<<X<<endl;
    }
}