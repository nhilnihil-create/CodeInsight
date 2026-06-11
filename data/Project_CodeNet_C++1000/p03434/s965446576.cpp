#include <iostream>
#include <vector>

using namespace std;

void descendingOrderSort(vector<int>& cards);
void swap(int& left, int& right);

int main() {
    int numOfCards = 0;
    cin >> numOfCards;
    vector<int> cards;
    int number;
    for (int i = 0; i < numOfCards; ++i) {
        cin >> number;
        cards.push_back(number);
    }
    
    descendingOrderSort(cards);
    
    int scoreOfAlice = 0;
    for (size_t i = 0; i < cards.size(); i += 2) {
        scoreOfAlice += cards.at(i);
    }
    
    int scoreOfBob = 0;
    for (size_t i = 1; i < cards.size(); i += 2) {
        scoreOfBob += cards.at(i);
    }    
    
    cout << scoreOfAlice - scoreOfBob << endl;
}
        
void descendingOrderSort(vector<int>& cards) {
    for (size_t i = cards.size() - 1; i > 0; --i) {
        for (size_t j = 0; j < i; ++j) {
            if (cards.at(j) < cards.at(j + 1)) {
                swap(cards.at(j), cards.at(j + 1));
            }
        }
    }
}    

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}