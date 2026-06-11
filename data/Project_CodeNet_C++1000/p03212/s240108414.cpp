#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<cmath>
using namespace std;
void addnumber(string, string);
int counter = 0;
long N;
int main(){
    cin >> N;
    addnumber("", "7");
    addnumber("", "5");
    addnumber("", "3");
    cout << counter << endl;
    return 0;
}

void addnumber(string currentNumber, string nextNumber){
    currentNumber = currentNumber + nextNumber;

    long currentIntNumber = stol(currentNumber);
    if (currentIntNumber > N){
        return;
    }

    bool count753[3];
    for(int i = 0; i < 3; i++){
        count753[i] = false;
    }
    for(int i = 0; i < currentNumber.length(); i++){
        if(currentNumber[i] == '7'){
            count753[0] = true;
        }
        else if(currentNumber[i] == '5'){
            count753[1] = true;
        }
        else if(currentNumber[i] == '3'){
            count753[2] = true;
        }
    }
    bool flag = true;
    for(int i = 0 ; i < 3; i++){
        if(count753[i] == false){
            flag = false;
        }
    } 

    if(flag == true){
        counter++;
    }
    //七五三数ならcount++
    addnumber(currentNumber, "3");
    addnumber(currentNumber, "5");
    addnumber(currentNumber, "7");
    
}