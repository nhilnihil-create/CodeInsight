#include<bits/stdc++.h>
using namespace std;

int n, A, B, C;
int l[8] = {0};
int cost = 1000000;
int how_many_bamboos = 0;
void dfs(int i, int a, int b, int c){
    if(i == n){
        if(a*b*c == 0) return ;
        cost = min (cost ,10*max(0,how_many_bamboos-3) + abs(a-A) + abs(b-B) + abs(c-C));
    }
    else{
        dfs(i+1,a,b,c);
        how_many_bamboos += 1;
        dfs(i+1,a+l[i],b,c);
        dfs(i+1,a,b+l[i],c);
        dfs(i+1,a,b,c+ l[i]);
        how_many_bamboos -= 1;
    }
}


int main(){
    cin >> n >> A >> B >> C;
    for (int i = 0; i < n; i++)
    {
        cin >> l[i];
    }
    dfs(0,0,0,0);
    cout << cost << endl;
}