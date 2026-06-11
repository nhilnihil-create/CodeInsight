/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+5;

int ar[N];

int main(){
    for(int i = 1; i <= 3; i++){
        scanf("%d" , &ar[i]);
    }
    sort(ar + 1 , ar + 3 + 1);
    if(ar[1] == ar[2]){
        printf("%d\n" , ar[3]);
    } else {
        printf("%d\n" , ar[1]);
    }
}
