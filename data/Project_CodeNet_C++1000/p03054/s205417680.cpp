#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

pair<int,int> move(char c){
    int a=0,b=0;
    if(c == 'U'){
        a = -1;
    }else if(c == 'D'){
        a = 1;
    }else if(c == 'L'){
        b = -1;
    }else if(c == 'R'){
        b = 1;
    }
    return pair<int,int>{a,b};
}

bool solve(int H,int W,int N, string& S, string& T, char taka, char aoki, int x, int y){
    for (int i = 0; i < N; i++)
    {
        // cout<<i<<endl;
        // cout<<x<<y<<endl;
        if(S[i] == taka){
            // cout<<"!"<<endl;
            pair<int,int> m = move(taka);
            x += m.first;
            y += m.second;
        }
        if(x < 0 || x >= H || y < 0 || y >= W){
            // cout<<taka<<aoki<<endl;
            return false;
        }
        if(T[i] == aoki){
            pair<int,int> m = move(aoki);
            x += m.first;
            y += m.second;
            if(x < 0 || x >= H){
                x -= m.first;
            }
            if(y < 0 || y >= W){
                y -= m.second;
            }
        }
    }
    return true;
}

int main(){
    int H,W,N;cin>>H>>W>>N;
    int sr,sc;cin>>sr>>sc;
    sr--;sc--;
    string S,T;cin>>S>>T;
    if(!solve(H,W,N,S,T,'U','D',sr,sc) || !solve(H,W,N,S,T,'R','L',sr,sc)
        || !solve(H,W,N,S,T,'D','U',sr,sc) || !solve(H,W,N,S,T,'L','R',sr,sc)){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }

}