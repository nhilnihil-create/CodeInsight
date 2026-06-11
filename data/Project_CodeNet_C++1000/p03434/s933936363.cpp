#include <iostream>
#include <vector>

using namespace std;

void ascendingOrderSort(vector<int>& cards);
void swap(int& left, int& right);
bool drawCard(vector<int>& cards, int& score);

int main() {
    int numOfCards = 0;
    cin >> numOfCards;
    vector<int> cards;
    int number;
    for (int i = 0; i < numOfCards; ++i) {
        cin >> number;
        cards.push_back(number);
    }
    
    ascendingOrderSort(cards);
    
    int scoreOfAlice = 0;
    int scoreOfBob = 0;
    while (true) {
        if(!drawCard(cards,scoreOfAlice)) {
            break;
        }
        if(!drawCard(cards,scoreOfBob)) {
            break;
        }
    }
    
    cout << scoreOfAlice - scoreOfBob << endl;
}
        
void ascendingOrderSort(vector<int>& cards) {
    for (size_t i = 0U; i < cards.size(); ++i) {
        for (size_t j = i + 1U; j < cards.size(); ++j) {
            if (cards.at(i) > cards.at(j)) {
                swap(cards.at(i), cards.at(j));
            }
        }
    }
}    

void swap(int& left, int& right) {
    int temp = left;
    left = right;
    right = temp;
}

bool drawCard(vector<int>& cards, int& score) {
    if (cards.empty()) {
        return false;
    } else {
        score += *cards.rbegin();
        cards.pop_back();
        return true;
    }
} 