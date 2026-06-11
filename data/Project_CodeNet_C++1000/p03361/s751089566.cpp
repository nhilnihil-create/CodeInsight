/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

#define forn(i,n) for(int i=0;i<n;i++)

using namespace std;
typedef long long ll;

int main(){
        
    ios_base::sync_with_stdio(0);
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    int h,w;
    cin>>h>>w;
    char x[h][w];
    forn(i,h)   forn(j,w)   cin>>x[i][j];
    
    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};
    
    
    forn(i,h){
        forn(j,w){
            if(x[i][j]=='#'){
                bool flag = false;
                forn(k,4){
                    int t = i + dx[k];
                    int s = j + dy[k];
                    if((t>=0 && t<h) && (s>=0 && s<w)){
                        if(x[t][s]=='#'){
                            flag = true;
                            break;
                        }
                    }
                }
                if(!flag){
                    cout<<"No\n";
                    return 0;
                }
            }
        }
    }
    cout<<"Yes\n";
    return 0;
}

