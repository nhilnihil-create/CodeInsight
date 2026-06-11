#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <map>
#include <vector>
#include <set>
#include <algorithm>
#include <sstream>
#include <queue>
#include <cctype>
#include <cmath>
#include <fstream>

using namespace std;

typedef long long ll;
#define REP(i,k) for(int (i)=0;(i)<(k);(i)++)
#define INF ~(1<<31)
#define CLR(a) memset((a),0,sizeof((a)))
#define EPS 1e-9
#define DBG 1
#define D(s,v) if(DBG) cout<<(s)<<": "<<(v)<<endl;
#define DVEC(s,v) if(DBG) {cout<<(s)<<": "; for(int i=0;i<(v).size();i++) cout<<(v)[i]<<" "; cout<<endl;}
#define DARR(s,v,n) if(DBG) {cout<<(s)<<": "; for(int i=0;i<n;i++) cout<<(v)[i]<<" "; cout<<endl;}

int X,Y;
int O = 8001;
string S;

bool can(bool myTurn, int mydir, int mypos,int dest){
    bool can[2][2][8001*2]; //spos, dir, pos
    CLR(can);
    
    for(int dir=0;dir<2;dir++)
        can[0][dir][dest] = 1;

    bool turn = myTurn;
    for(int i=0;i<S.size();i++){
        if(S[i]=='T') turn ^= 1;
    }

    for(int spos=S.size()-1;spos>=0;spos--){
        if(S[spos]=='T') turn^=1;
        for(int dir=0;dir<2;dir++)
            for(int pos=0;pos<8001*2;pos++){
            if(turn){
                if(S[spos]=='F'){
                    if(dir)
                        can[1][dir][pos] = can[0][dir][pos+1];
                    else
                        can[1][dir][pos] = can[0][dir][pos-1];
                }
                else{
                    can[1][dir][pos] = can[0][dir][pos];
                }
            }
            else{
                if(S[spos]=='F'){
                    can[1][dir][pos] = can[0][dir][pos];
                }
                else{
                    can[1][dir][pos] |= can[0][0][pos];
                    can[1][dir][pos] |= can[0][1][pos];
                }
            }
        }

        for(int dir=0;dir<2;dir++)
        for(int pos=0;pos<8001*2;pos++){
            can[0][dir][pos] = can[1][dir][pos];
            can[1][dir][pos] = 0;
        }
    }

    if(myTurn) return can[0][mydir][mypos];
    else return can[0][0][mypos] | can[0][1][mypos];
}

int main(){
    ios_base::sync_with_stdio(0);
    string s;
    while(getline(cin,s)){
        int x,y;
        cin >> x >> y;

        X = x; Y = y; S = s;

        bool canGo = can(1,1,O,O+x) && can(0,0,O,O+y);
        if(canGo){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }

        getline(cin,s);
    }
}