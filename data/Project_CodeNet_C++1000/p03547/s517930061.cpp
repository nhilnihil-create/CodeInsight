#include <iostream>
#include <vector>
using namespace std;

int main(){
    char x,y;
    int x2, y2;

    cin >> x >> y;

    if(x == 'A'){
        x2 = 10;
    } else if(x == 'B'){
        x2 = 11;
    }else if(x == 'C'){
        x2 = 12;
    }else if(x == 'D'){
        x2 = 13;
    }else if(x == 'E'){
        x2 = 14;
    }else if(x == 'F'){
        x2 = 15;
    }

    if(y == 'A'){
        y2 = 10;
    } else if(y == 'B'){
        y2 = 11;
    }else if(y == 'C'){
        y2 = 12;
    }else if(y == 'D'){
        y2 = 13;
    }else if(y == 'E'){
        y2 = 14;
    }else if(y == 'F'){
        y2 = 15;
    }

    if(x == y){
        cout << "=" << endl;
    } else if(x > y){
        cout << ">" << endl;
    } else if(x < y){
        cout << "<" << endl;
    }
}