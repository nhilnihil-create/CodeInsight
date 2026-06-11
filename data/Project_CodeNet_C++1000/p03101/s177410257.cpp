#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
string alphabet = "abcdefghijklmnopqrstuvwxyz";
string ALPHABET = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main(){
 int H , W , h , w;
 cin >> H >> W >> h >> w;
 cout << H * W - h * W - H * w + h * w << endl;
}