#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    if(n==1){
        cout << 1 << endl;
        return 0;
    }else{
        vector <unsigned long long>l;
        l.push_back(2);
        l.push_back(1);//n==1 size==2 
        while(true){
           l.push_back(l[l.size()-1]+l[l.size()-2]);
           //cout << l.size() <<" "<< l.back() << endl;
           if(l.size()==n+1){
               cout << (unsigned long long)l.back() << endl;
               return 0;
           } 
        }
    }
    return 0;
}