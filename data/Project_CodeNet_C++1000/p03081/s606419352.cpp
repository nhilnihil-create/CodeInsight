#include <stdio.h>
using namespace std;

int n, q;
char s[200001], t[200000], d[200000];

char last_place(int index){
    for(int i=0; i<q; i++){
        if(s[index]==t[i]){
            if(d[i]=='R') index++;
            else index--;
        }
        if(index==-1) return 'l'; // lift
        else if(index==n) return 'r'; // right
    }
    return 'i'; // inside
}

int l_limit(int l, int r){
    int mid = (r + l) / 2;
    if(mid == r) return mid-1;
    else if(mid == l) return mid;

    char result = last_place(mid);
    if(result == 'l') return l_limit(mid, r);
    return l_limit(l, mid);
}

int r_limit(int l, int r){
    int mid = (r + l) / 2;
    if(mid == r) return mid;
    else if(mid == l) return mid + 1;

    char result = last_place(mid);
    if(result == 'r') return r_limit(l, mid);
    return r_limit(mid, r);
}

int main(){
    scanf("%d%d", &n, &q);
    scanf("%s", s);
    for(int i=0; i<q; i++){
        scanf(" %c %c", &t[i], &d[i]);
    }

    int vanish_left = l_limit(-1, n) + 1;
    int vanish_right = n - r_limit(-1, n);

    printf("%d\n", n - vanish_left - vanish_right);
    return 0;
}
