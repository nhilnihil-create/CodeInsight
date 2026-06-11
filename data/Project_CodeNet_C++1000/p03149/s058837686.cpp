#include <iostream>

using namespace std;

int main(){
        bool a=false,b=false,c=false,d=false;
    for(int i=0;i<4;i++){
        int x;
        cin >> x;
        switch (x)
        {
        case 1:
            a = true;
            break;
        case 9:
            b = true;
            break;
        case 7:
            c = true;
            break;
        case 4:
            d = true;
            break;
        }
    }
    if(a&&b&&c&&d){
        cout <<"YES" <<endl;
    }
    else{
        cout <<"NO"<<endl;
    }
}