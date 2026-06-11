
#include <iostream>
using namespace std;
 
int main() {
    
    int H,W;
    cin >> H >> W;

    string s[H];
    
    for (int i=0 ; i<H ;i++){
        cin >> s[i];
    }
    
    char M[H+2][W+2];
    
    for (int j=0 ; j<W+2 ;j++){
        M[0][j] = '.';
        M[H+1][j] = '.';
    }
    for (int i=0 ; i<H+2 ;i++){
        M[i][0] = '.';
        M[i][W+1] = '.';
    }
    
    for (int i=1 ; i<H+1 ;i++){
        for(int j=1 ;j<W+1 ;j++){
            M[i][j] = s[i-1].at(j-1);
        }
    }
    
    /*
    for (int i=0 ; i<H+2 ;i++){
             for(int j=0 ;j<W+2 ;j++){
                 cout << M[i][j] ;
             }
          cout <<endl;
      }
     */
    
    cout <<endl;
    
    for (int i=1 ; i<H+1 ;i++){
        for(int j=1 ;j<W+1 ;j++){
            
            if( M[i][j] == '#'){
                cout << '#';
            }
            else{
                int counter =0;
                
                for (int m=-1 ; m<2 ;m++){
                    for(int n=-1 ; n<2 ;n++){
                        if( M[i+m][j+n] == '#'){
                            counter++ ;
                        }
                    }
                }
                cout << counter ;
            }
        }
        cout <<endl;
    }
    
    cout <<endl;
}