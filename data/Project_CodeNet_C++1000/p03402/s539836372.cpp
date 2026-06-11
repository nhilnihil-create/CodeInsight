#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF = 1e9;
const int MOD = 1000000007;
const int MAX = 1000000;

int main(){
        int a,b;
        cin >> a >> b;
        if(a == 1 && b == 1){
                cout << 1 << " " << 2 << endl;
                cout << "#." << endl;
                return 0;
        }
        bool sw = false;
        if(a > b) {swap(a,b);sw = true;}
        vector<vector<char>> maze(99,vector<char>(99,'.'));
        int n = b+a-2;
        int i = 1,j = 1;
        while(n > 0){
                maze[i][j] = '#';
                j += 2;
                if(j > 98){
                        j = 1;
                        i += 2;
                }
                n--;
        }

        n = a-1;
        i = 0;
        j = 1;
        while(n > 0){
                maze[i][j] = '#';
                maze[i+1][j-1] = '#';
                j += 2;
                if(j > 98){
                        i += 2;
                        j = 1;
                }
                n--;
        }

        if(a==1){
                maze[98][98] = '#';
        }

        cout << 99 << " " << 99 << endl;
        if(sw){
                rep(i,99){
                        rep(j,99){
                                cout << (maze[i][j] == '.' ? '#' : '.') ;
                        }
                cout << endl;
                }
        }
        else{
            rep(i,99){
                    rep(j,99){
                            cout << maze[i][j] ;
                    }
                    cout << endl;
            }
        }
}