#include <iostream>
#include <cmath>
using namespace std;
int return_result(int);
int main()
{
    int up, down,s;
    int up_result, down_result;
    cin >> s;
    up = floor(s/100);
    down = s % 100;
    
    up_result = return_result(up);
    down_result = return_result(down);

    if(up_result ==0){
        if(down_result ==0 || down_result ==2){
            cout <<"NA" <<endl;
            return 0;
        }
        else if(down_result == 1){
            cout << "YYMM" <<endl;
            return 0;            
        }

    }

    if(down_result ==0){
        if(up_result ==0 || up_result ==2){
            cout <<"NA" <<endl;
            return 0;
        }
        else if(up_result == 1){
            cout << "MMYY" <<endl;
            return 0;            
        }

    }    


    if(up_result ==2 && down_result == 2){
        cout << "NA" <<endl;
        return 0;
    }

    if(down_result ==1 && up_result == 2){
        cout << "YYMM" <<endl;
        return 0;
    }

    if(down_result ==2 && up_result == 1){
        cout << "MMYY" <<endl;
        return 0;
    }
    if(up_result == 1 && down_result == 1){
    cout << "AMBIGUOUS" << endl;
    return 0;
    }
    return 0;
}

int return_result(int a)
{
    if(0 < a && a <= 12){
        return 1; //return month
    }
    else if(a >= 13){
        return 2; //return year
    }

    else if(a == 0){
        return 0; //return ambigious
    }

    return 4;

}