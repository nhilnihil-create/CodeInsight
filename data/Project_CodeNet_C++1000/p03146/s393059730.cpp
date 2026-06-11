#include <bits/stdc++.h>
using namespace std;
long long f(long long in){
    if(in%2==0){
        return in/2;
    }else{
        return (3*in+1);
    }
}
int main(){
    long long s;
    cin >> s;
    vector <long long> a;
    a.push_back(s);
    long long cnt = 1;
    while(true){
        cnt++;
        long long tmp = f(a.back());
        for(long long i = 0; i < a.size(); i++){
            if(a[i]==tmp){
                cout << cnt << endl;
                return 0;
            }
        }
        a.push_back(tmp);
    }
    return 0;
}
