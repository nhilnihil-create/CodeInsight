#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void addWordCount(const vector<string>& cards, map<string, int>& wordCount);
void subWordCount(const vector<string>& cards, map<string, int>& wordCount);
int getMaxValue(const map<string, int>& wordCount);


int main() {
    int numOfBlueCard = 0;
    cin >> numOfBlueCard;
    vector<string> blueCards;
    for (int i = 0; i < numOfBlueCard; ++i) {
        string blueCard;
        cin >> blueCard;
        blueCards.push_back(blueCard);
    }

    int numOfRedCard = 0;
    cin >> numOfRedCard;
    vector<string> redCards;
    for (int i = 0; i < numOfRedCard; ++i) {
        string redCard;
        cin >> redCard;
        redCards.push_back(redCard);
    }
    
    map<string, int> wordCount;
    addWordCount(blueCards, wordCount);
    subWordCount(redCards, wordCount);
    
    cout << getMaxValue(wordCount) << endl;
}

void addWordCount(const vector<string>& cards, map<string, int>& wordCount) {
    for (string card : cards) {
        ++wordCount[card];
    }
}

void subWordCount(const vector<string>& cards, map<string, int>& wordCount) {
    for (string card : cards) {
        --wordCount[card];
    }
}

int getMaxValue(const map<string, int>& wordCount) {
    int maxValue = 0;
    for (auto word : wordCount) {
        if (word.second > maxValue) maxValue = word.second;
    }
    return maxValue;
} 