#include<bits/stdc++.h>
using namespace std;

int N, A, B;
int main(){
    scanf("%d%d%d",&N,&A,&B);
    if(A>N || B>N) return !printf("-1\n");
    vector<int> v(N); for(int i=0;i<N;i++) v[i] = i+1;
    vector<int> ret;

    for(int i=0;i<A;i++){
        ret.push_back(v.back());
        v.pop_back();
    }
    reverse(ret.begin(),ret.end());

    int b = 1;
    while(!v.empty()){
        if(b>=B) return !printf("-1\n");
        int n = v.size();
        int x = b+1+n-B;
        if(x<=0) return !printf("-1\n");

        int cur = min(x, A);
        vector<int> tmp;
        for(int i=0;i<cur;i++){
            tmp.push_back(v.back());
            v.pop_back();
        }
        while(!tmp.empty()){
            ret.push_back(tmp.back());
            tmp.pop_back();
        }
        b++;
    }
    if(b!=B) return !printf("-1\n");

    for(int x:ret) printf("%d ", x);
    printf("\n");
}
