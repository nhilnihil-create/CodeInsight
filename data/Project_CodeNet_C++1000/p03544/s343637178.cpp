#include <iostream>
#include <vector>
 
using namespace std;
 
void calcLucasSequence(vector<long>& lucasSequence, const int numOfTerm);
 
int main() {
    int numOfTerm = 0;
    cin >> numOfTerm;
    
    vector<long> lucasSequence;
    calcLucasSequence(lucasSequence, numOfTerm);
    
    cout << lucasSequence.at(numOfTerm) << endl;  
}
 
void calcLucasSequence(vector<long>& lucasSequence, const int numOfTerm) {
    const long INITIAL_TERM = 2;
    const long SECOND_TERM = 1;
    
    lucasSequence.push_back(INITIAL_TERM);
    lucasSequence.push_back(SECOND_TERM);
    for (int termIndex = lucasSequence.size(); termIndex <= numOfTerm; ++termIndex) {
        lucasSequence.push_back(lucasSequence.at(termIndex - 1) + lucasSequence.at(termIndex - 2));
    }
}