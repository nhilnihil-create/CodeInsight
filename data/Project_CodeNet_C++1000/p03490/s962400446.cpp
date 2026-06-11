#include <bits/stdc++.h>
using namespace std;
const int MAX = 8005;
const int MID = 8000;
char S[MAX];
int N, X, Y, cc;
bitset<MAX * 2 + 1> xbit, ybit;

int main(){
    scanf("%s", S);
    N = strlen(S);
    scanf("%d %d", &X, &Y);
    int i = 0;
    for(; S[i] == 'F'; i++);
    xbit.set(MID), ybit.set(MID);
    xbit <<= i;
    int st = 1;
    for(; i < N; i++){
        if(S[i] == 'F')     cc++;
        else{
            if(st)  xbit = (xbit << cc) | (xbit >> cc);
            else    ybit = (ybit << cc) | (ybit >> cc);
            st ^= 1;
            cc = 0;
        }
    }
    if(cc){
        if(st)  xbit = (xbit << cc) | (xbit >> cc);
        else    ybit = (ybit << cc) | (ybit >> cc);
    }
    if(xbit[MID + X] && ybit[MID + Y])  puts("Yes");
    else puts("No");
    return 0;
}
