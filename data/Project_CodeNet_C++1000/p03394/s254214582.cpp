#include <iostream>

using namespace std;

int main(){
    int i,n,k=0;
    cin >> n;
    if(n<=6){
        if(n==3){
            cout << 2 <<" " << 5 << " "<< 63 << endl;
            return 0;
        }
        if(n==4){
            cout << 2 <<" "<< 3 <<" "<< 4<< " " << 9 << endl;
            return 0;
        }
        if(n==5){
            cout << 2 << " "<< 3 << " "<< 4 << " " << 6 << " " << 9 << endl;
            return 0;
        }
        if(n==6){
            cout << 2 << " "<< 3 << " " << 4 << " "<< 6 << " "<< 9 << " "<< 12 << endl;
            return 0;
        }
    }
    if(n%8==0){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " ";
                k++;
            }
            if(k==n){
                break;
            }
        }
    }else if(n%8==1){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                cout << i+6 << " " ;
                break;
            }
        }
    }else if(n%8==2){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                cout << i+2 << " " << i+4 ;
                break;
            }
        }
    }else if(n%8==3){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                cout << i+3 << " " << i+6 << " " << i+9 ;
                break;
            }
        
        }
    }else if(n%8==4){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                cout << i+2 << " " << i+3 << " " << i+4 << " " << i+9 ;
                break;
            }
        }
    }else if(n%8==5){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                cout << i+2 << " " << i+4 << " " << i+6 << " " << i+8 << " " << i+10;
                break;
            }
        }
    }else if(n%8==6){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n/8*8){
                 cout << i+2 << " " << i+4 << " " << i+6 << " " << i+8 << " " << i+10 << " " << i+12;
                 break;
            }
        }
    }
    else if(n%8==7){
        for(i=1;i<=30000;i++){
            if(i%2==0 || i%3==0){
                cout << i << " " ;
                k++;
            }
            if(k==n){
                break;
            }
        }
    }
    cout << endl;
}

