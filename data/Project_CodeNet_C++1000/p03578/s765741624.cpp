#include <iostream>
#include <cstdio>
#include <map>
using namespace std;

int main(){
    long long n, m;
    map<long long, long long> D;

    cin >> n;

    long long d;
    for(long long i = 0; i < n; i++){
        cin >> d;
        if(D.find(d) == D.end()){
            D[d] = 1;
        }
        else{
            D[d] += 1;
        }
    }

    cin >> m;

    bool flag = true;

    long long t;
    for(long long i = 0; i < m; i++){
        cin >> t;
        if(D.find(t) == D.end()){
            flag = false;
            break;
        }
        else{
            D[t] -= 1;
            if(D[t] == 0){
                D.erase(t);
            }
        }
    }

    if(flag == true){
        printf("YES\n");
    }
    else{
        printf("NO\n");
    }

    return 0;
}