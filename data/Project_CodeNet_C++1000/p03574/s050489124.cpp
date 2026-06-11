#include <iostream>
using namespace std;

int main() {
    int x,y;
    char cell[60][60];
    cin >> y >> x;
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            cin >> cell[i][j];
        }
    }
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            if(cell[i][j]=='.'){
                int total=0;
                if(cell[i-1][j]=='#')total++;
                if(cell[i][j-1]=='#')total++;
                if(cell[i+1][j]=='#')total++;
                if(cell[i][j+1]=='#')total++;
                if(cell[i-1][j-1]=='#')total++;
                if(cell[i+1][j-1]=='#')total++;
                if(cell[i-1][j+1]=='#')total++;
                if(cell[i+1][j+1]=='#')total++;
                cell[i][j]=total+'0';
            }
        }
    }
    for(int i=1;i<=y;i++){
        for(int j=1;j<=x;j++){
            cout << cell[i][j];
        }
        cout << endl;
    }
}