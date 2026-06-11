#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int N;
    cin >> N;
    char s;
    bool b = true;
    for(int i; i<N; ++i){
        cin >> s;
        if(s == 'Y'){
            printf("Four");
            b = false;
            break;
        }
    }
    if(b){
        printf("Three");
    }
}