#include <iostream>
using namespace std; 

int arr[5];

void findTasty(){
    int a = arr[0];
    int b = arr[1];
    int c = arr[2]; 

    int count = 0; 
    int antidote = a + b + 1; 
    int poisonous = c; 

    if(antidote  >= poisonous){
      count = count + poisonous; 
      count = count + b; 
    }
    else{
      count = count + antidote; // Num poisonous
      count = count + b;
    }

    // Since tasty cookies are finished
    cout << count << endl;
}

int main(){
    for(int i = 0; i < 3; i++){
        cin >> arr[i];
    }
    findTasty();
}