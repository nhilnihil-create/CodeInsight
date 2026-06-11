#include <iostream>
using namespace std;
 
int main()
{
    int h, w;
    cin >> h >> w;
    char m[h][w], M[h][w];
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> m[i][j];
            if(m[i][j] == '#') M[i][j] = '#';
            else M[i][j] = '0';
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            if(m[i][j] == '#') {
                if(i!=0 && M[i-1][j] != '#') M[i-1][j]++;
                if(i!=h-1 && M[i+1][j] != '#') M[i+1][j]++;
                if(j!=0 && M[i][j-1] != '#') M[i][j-1]++;
                if(j!=w-1 && M[i][j+1] != '#') M[i][j+1]++;
                if(i!=0 && j!=0 && M[i-1][j-1] != '#') M[i-1][j-1]++;
                if(i!=0 && j!=w-1 && M[i-1][j+1] != '#') M[i-1][j+1]++;
                if(i!=h-1 && j!=0 && M[i+1][j-1] != '#') M[i+1][j-1]++;
                if(i!=h-1 && j!=w-1 && M[i+1][j+1] != '#') M[i+1][j+1]++;
                
            }
        }
    }
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cout << M[i][j];
        }
        cout << endl;
    }
}